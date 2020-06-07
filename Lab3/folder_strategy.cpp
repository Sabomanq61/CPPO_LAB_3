#include "folder_strategy.h"
#include <QFileInfo>
#include <QDir>
#include <vector>
#include <QTextStream>

std::shared_ptr<DirInfo> StrategyFolder::Explore(const QString& path) const
{
    using namespace std;

    QFileInfo file(path);

    if(file.isDir())// Проверка на то что элемент является директорией
    {
        std::shared_ptr<DirInfo> dirInfo(new DirInfo{});
        dirInfo->path_ = path;
        std::map<QString, uint64_t> temp{}; // Временное хранилище для хранения размеров объекта .
        QDir dir(path);

        for(QFileInfo fileInfo : dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System | QDir::NoSymLinks,QDir::Name))
        {
            QString name = fileInfo.fileName();
            int64_t size{};

            size = Size(fileInfo.absoluteFilePath());

            dirInfo->totalSize_ += size;
            temp.insert({fileInfo.fileName(), size});
        }

        for(auto it = temp.begin() ; it != temp.end(); ++it)
        {
            dirInfo->hash_.insert({it->first, (double)it->second / dirInfo->totalSize_ * 100});
        }

        return dirInfo;
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









