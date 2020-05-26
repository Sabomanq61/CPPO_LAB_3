#include "folder_strategy.h"
#include <QFileInfo>
#include <QDir>
#include <vector>
#include <QTextStream>

void StrategyFolder::Explore(const QString& path) const
{
    using namespace std;

    QFileInfo file(path);

    if(file.isDir())// Проверка на то что элемент является директорией
    {
        QDir dir(path);
        vector<QString> files;
        vector<int64_t> sizes;
        int64_t total_size = 0;

        for(QFileInfo fileInfo : dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System | QDir::NoSymLinks,QDir::Name))
        {
            files.push_back(fileInfo.fileName());

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
            for(size_t it = 0; it < files.size(); ++it)
            {
                QTextStream(stdout) << files[it] << "  " << (double)sizes[it]/total_size*100 << "%" << endl << flush;
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
            if(it.isDir())
            {
                total_size += Size(it.absoluteFilePath());// Рекурсия для вычисления размера папки содержащей еще папки.
            }
            else total_size+=it.size();
        }
        return total_size;
    }
    return 0;
}









