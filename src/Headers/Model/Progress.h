#pragma once
#include <map>
#include <string>

namespace MansionEscape
{
class RoomView;

class Progress
{
public:
  typedef std::map<std::string, bool> FlagMap;

  Progress();
  bool GetFlag(std::string const& flag) const;
  void SetFlag(std::string const& flag, bool value);

  FlagMap const& GetFlags() const;
  void SetFlags(FlagMap const& newMap);

private:
  FlagMap _flagMap;
};
}
