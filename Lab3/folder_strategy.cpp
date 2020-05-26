#include "folder_strategy.h"
#include <QFileInfo>
#include <QDir>
#include <vector>
#include <QTextStream>

void StrategyFolder::Explore(const QString& path) const
{
    using namespace std;

    QFileInfo file(path);

    if(file.isDir())
    {
        QDir dir(path);
        vector<QString> names;
        vector<int64_t> sizes;
        int64_t total_size = 0;

        for(QFileInfo fileInfo : dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System | QDir::NoSymLinks,QDir::Name))
        {
            names.push_back(fileInfo.fileName());

            if(fileInfo.isDir())
            {
                sizes.push_back(Size(fileInfo.absoluteFilePath()));
            }
            else
            {
                sizes.push_back(fileInfo.size());
            }
            total_size += sizes[sizes.size() - 1];
        }

        if(total_size)
        {
            for(size_t it = 0; it < names.size(); ++it)
            {
                QTextStream(stdout) << names[it] << "  " << (double)sizes[it]/total_size*100 << "%" << endl << flush;
            }
        }
        else
            QTextStream(stdout) << "Folder is empty" << endl << flush;
    }
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
            if(it.isDir())//если папка,то считаем ее размер,иначе размер файла
            {
                total_size+=Size(it.absoluteFilePath());
            }
            else total_size+=it.size();
        }
        return total_size;
    }
    return 0;
}









