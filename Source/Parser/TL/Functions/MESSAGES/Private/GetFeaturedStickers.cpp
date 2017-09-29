#include "../Public/GetFeaturedStickers.h"


//begin namespace block
namespace MESSAGES
{

GetFeaturedStickers::GetFeaturedStickers()
{
	this->_ConstructorID = 766298703;
	this->_ContentRelated = true;
}

GetFeaturedStickers::GetFeaturedStickers(int32 hash)
{
	this->_ConstructorID = 766298703;
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
	this->_Responded = true;
}
GetFeaturedStickers::~GetFeaturedStickers()
{

}
}//end namespace block
