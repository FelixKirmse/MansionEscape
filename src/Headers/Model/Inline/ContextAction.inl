template<class Archive>
void ContextAction::serialize(Archive& ar, unsigned int const version)
{
  ar & BOOST_SERIALIZATION_NVP(_label);
  ar & BOOST_SERIALIZATION_NVP(_reaction);
  ar & BOOST_SERIALIZATION_NVP(_forbiddenFlags);
  ar & BOOST_SERIALIZATION_NVP(_requiresFlags);
  ar & BOOST_SERIALIZATION_NVP(_grantsFlags);
  ar & BOOST_SERIALIZATION_NVP(_removesFlags);
  ar & BOOST_SERIALIZATION_NVP(_removesItems);
  ar & BOOST_SERIALIZATION_NVP(_grantsItems);
}
