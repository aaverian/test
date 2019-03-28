
#include "qgitindexmodel.h"

#include <qgitindexentry.h>

namespace LibQGit2
{

IndexModel::IndexModel(const Index& index, QObject *parent)
    : QAbstractListModel(parent)
    , m_index(index)
{
}

IndexModel::~IndexModel()
{

}

int IndexModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 0;
    } else {
        return m_index.entryCount();
    }
}

QVariant IndexModel::data(const QModelIndex& index, int role) const
{
    if (index.parent().isValid())
        return QVariant();



    if (index.column() != 0)
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole) 
    {
        IndexEntry entry = m_index.getByIndex(index.row());
        return entry.path();
    } 
    else {
        return QVariant();
    }
}

}
