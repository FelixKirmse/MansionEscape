template<class Archive>
void ItemInfo::save(Archive& ar, unsigned int const version) const
{
  ar & BOOST_SERIALIZATION_NVP(_name);
  ar & BOOST_SERIALIZATION_NVP(_commentString);
}

template<class Archive>
void ItemInfo::load(Archive& ar, unsigned int const version)
{
  using namespace boost;
  ar & BOOST_SERIALIZATION_NVP(_name);
  ar & BOOST_SERIALIZATION_NVP(_commentString);

  format picturePath(ItemPicturePath);
  picturePath
      % _name
      % _name;
  _picture = QPixmap(QString(picturePath.str().c_str()));
}
