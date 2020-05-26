#include "folder_strategy.h"
#include <QFileInfo>
#include <QDir>
#include <vector>
#include <iostream>
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

        for(QFileInfo fileInfo : dir.entryInfoList((QDir::Dirs | QDir::Files | QDir::System)))
        {
            names.push_back(fileInfo.fileName());

            if(fileInfo.isDir())
            {
                //sizes.push_back()TODO SIZE DIR
            }
            else
            {
                sizes.push_back(fileInfo.size());
            }
            total_size += sizes.end().operator*();
        }

        if(!total_size)
        {
            for(size_t it = 0; it < names.size(); ++it)
            {

            }
        }
    }
}










