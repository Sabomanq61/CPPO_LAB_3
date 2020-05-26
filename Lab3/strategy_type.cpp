#include "strategy_type.h"
#include <QFileInfo>
#include <QDir>
#include <vector>
#include <QTextStream>

void StrategyType::Explore(const QString& path ) const
{
    using namespace std;
    QFileInfo fileInfo(path);

    if(fileInfo.isDir())
    {
        QDir dir(path);
        vector<QString> names;
        int64_t total_size=0;
        map<QString,int64_t> hash;

        //проходим по всем элементам в папке
        for(QFileInfo it: dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System | QDir::NoSymLinks,QDir::Name))
        {
            //если папка то вычисляяем ее рамер
            if(it.isDir()) {
                Size(it.absoluteFilePath(),hash);
            }
            //иначе вычисляем размер файла
            else hash[it.suffix()]+=it.size();
        }
        for (const auto& it : hash)
        {
            //размер папки
            total_size += it.second;
            //список типов которые есть в папке
            names.push_back(it.first);
        }

        if(total_size)
        {
            for(size_t i = 0; i < names.size(); ++i)
            {
                QTextStream(stdout) << names[i] << ' ' << (double)hash[names[i]] / total_size * 100 << '%' << endl << flush;
            }
        }
        else
        {
            QTextStream(stdout) << "Folder is empty" << endl << flush;
        }
    }
}
int64_t StrategyType::Size(const QString& path, std::map<QString,int64_t>& hash) const
{
    QFileInfo fileInfo(path);
    if(fileInfo.isDir())
    {
        QDir dir(path);
        int64_t totalSize=0;
        //проходим по всем элементам папки
        for (QFileInfo it : dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System | QDir::NoSymLinks,QDir::Name)) {
            if(it.isDir()) {
                Size(it.absoluteFilePath(),hash);
            }
            else hash[it.suffix()]+=it.size();
        }
        return totalSize;
    }
    return 0;
}





















