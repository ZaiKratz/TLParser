#include "../Public/GetFeaturedStickers.h"


//begin namespace block
namespace MESSAGES
{

GetFeaturedStickers::GetFeaturedStickers()
{
	this->_ConstructorID = 1338682413;
	this->_ContentRelated = true;
}

GetFeaturedStickers::GetFeaturedStickers(int32 hash)
{
	this->_ConstructorID = 1338682413;
	this->_ContentRelated = true;
	this->hash = hash;
}
void GetFeaturedStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
}


void GetFeaturedStickers::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::FeaturedStickers*>(Reader.TGReadObject());
}
GetFeaturedStickers::~GetFeaturedStickers()
{

}
}//end namespace block
