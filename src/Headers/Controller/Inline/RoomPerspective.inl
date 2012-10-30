template<class Archive>
void RoomPerspective::save(Archive& ar, unsigned int const version) const
{
  ar & BOOST_SERIALIZATION_NVP(_label);
  ar & BOOST_SERIALIZATION_NVP(_contextActions);
  ar & BOOST_SERIALIZATION_NVP(_description);
  ar & BOOST_SERIALIZATION_NVP(_nextRoom);
  ar & BOOST_SERIALIZATION_NVP(_requiredFlagsForNextRoom);
  ar & BOOST_SERIALIZATION_NVP(_pictureConditions);
}

template<class Archive>
void RoomPerspective::load(Archive& ar, unsigned int const version)
{
  ar & BOOST_SERIALIZATION_NVP(_label);
  ar & BOOST_SERIALIZATION_NVP(_contextActions);
  ar & BOOST_SERIALIZATION_NVP(_description);
  ar & BOOST_SERIALIZATION_NVP(_nextRoom);
  ar & BOOST_SERIALIZATION_NVP(_requiredFlagsForNextRoom);
  ar & BOOST_SERIALIZATION_NVP(_pictureConditions);
  LoadPictures();
}
