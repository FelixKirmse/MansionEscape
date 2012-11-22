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
  FlagMap::iterator lowerBound = _flagMap.lower_bound(flag);
  if(lowerBound != _flagMap.end() && !(_flagMap.key_comp()(flag, lowerBound->first)))
    lowerBound->second = value;
  else
    _flagMap.insert(lowerBound, FlagMap::value_type(flag, value));
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
