#include "folder_strategy.h"
#include <QFileInfo>
#include <QDir>
#include <vector>
#include <QTextStream>

std::shared_ptr<DirInfo> StrategyFolder::Explore(const QString& path) const
{using namespace std;
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

int64_t StrategyFolder::Size(const QString &path) const
{
    QFileInfo fileInfo(path);

    if(fileInfo.isDir())
    {
        QDir dir(path);
        int64_t total_size=0;
        //Обход элементов папки
        for (QFileInfo it : dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System | QDir::NoSymLinks,QDir::Name))
        {
            if(it.isDir())
            {
                total_size += Size(it.absoluteFilePath());// Рекурсия для вычисления размера папки содержащей еще папки.
            }
            else total_size+=it.size();
        }
        return total_size;
    }
    return fileInfo.size();
}









