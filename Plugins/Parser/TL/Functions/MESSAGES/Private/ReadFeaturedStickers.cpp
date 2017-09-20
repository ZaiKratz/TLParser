#include "../Public/ReadFeaturedStickers.h"


//begin namespace block
namespace MESSAGES
{

ReadFeaturedStickers::ReadFeaturedStickers()
{
	this->_ConstructorID = 645992795;
	this->_ContentRelated = true;
}

ReadFeaturedStickers::ReadFeaturedStickers(TArray<unsigned long long> id)
{
	this->_ConstructorID = 645992795;
	this->_ContentRelated = true;
	this->id = id;
}
void ReadFeaturedStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	Writer.WriteLong(X);
	}
}


void ReadFeaturedStickers::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
ReadFeaturedStickers::~ReadFeaturedStickers()
{

}
}//end namespace block
