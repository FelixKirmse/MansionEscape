template<class Archive>
void Item::serialize(Archive& ar, unsigned int const version)
{
  ar & BOOST_SERIALIZATION_NVP(_itemInfo);
}
