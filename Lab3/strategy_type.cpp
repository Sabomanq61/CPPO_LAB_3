#include "strategy_type.h"
#include <QFileInfo>
#include <QDir>
#include <vector>
#include <QTextStream>

std::shared_ptr<DirInfo> StrategyType::Explore(const QString& path ) const
{
    using namespace std;
    QFileInfo fileInfo(path);

    if(fileInfo.isDir())
    {
        shared_ptr<DirInfo> result(new DirInfo{});
        QDir dir(path);
        result->path_ = path;

        map<QString, uint64_t> tempHash{};

        for(QFileInfo it : dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System | QDir::NoSymLinks,QDir::Name))
        {
            if(it.isDir())
            {
                result->totalSize_ += Size(it.absoluteFilePath(), tempHash);
            }
            else
            {
                tempHash[it.suffix()] += it.size();
                result->totalSize_ += it.size();
            }
        }

        for(const auto& it : tempHash)
        {
            result->hash_[it.first] = (double)it.second / result->totalSize_ * 100;
        }
        return result;
    }
    return nullptr;
}


int64_t StrategyType::Size(const QString& path, std::map<QString,uint64_t>& hash) const
{
    QFileInfo fileInfo(path);
    if(fileInfo.isDir())
    {
        QDir dir(path);
        uint64_t totalSize=0;
        //Обход элементов папки
        for (QFileInfo it : dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System | QDir::NoSymLinks,QDir::Name)) {
            if(it.isDir())
            {
                totalSize += Size(it.absoluteFilePath(),hash);
            }
            else
            {
                hash[it.suffix()]+=it.size();
                totalSize += it.size();
            }
        }
        return totalSize;
    }
    return 0;
}



















