#include "Model/Progress.h"

namespace MansionEscape
{
Progress::Progress()
  : _flagMap()
{
}

bool Progress::GetFlag(std::string const& flag) const
{
  return _flagMap.find(flag)->second;
}

void Progress::SetFlag(std::string const& flag, bool value)
{
  _flagMap[flag] = value;
}

Progress::FlagMap const& Progress::GetFlags() const
{
  return _flagMap;
}

void Progress::SetFlags(FlagMap const& newMap)
{
  _flagMap = newMap;
}
}
