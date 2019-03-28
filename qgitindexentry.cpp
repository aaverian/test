 

#include "qgitindexentry.h"
#include "qgitoid.h"

#include "private/pathcodec.h"

namespace LibQGit2
{

IndexEntry::IndexEntry(const git_index_entry *data)
    : d(data)
{
}

IndexEntry::IndexEntry(const IndexEntry& other)
    : d(other.d)
{
}

IndexEntry::~IndexEntry()
{

}

OId IndexEntry::id() const
{
    return OId(&d->id);
}

QString IndexEntry::path() const
{
    return PathCodec::fromLibGit2(d->path);
}

qint64 IndexEntry::fileSize() const
{
    return d->file_size;
}

int IndexEntry::stage() const {
    return git_index_entry_stage(d);
}

const git_index_entry *IndexEntry::data() const
{
    return d;
}

} // namespace LibQGit2
