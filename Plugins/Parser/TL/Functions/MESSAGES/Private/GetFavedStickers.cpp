#include "../Public/GetFavedStickers.h"


//begin namespace block
namespace MESSAGES
{

GetFavedStickers::GetFavedStickers()
{
	this->_ConstructorID = 235654689;
	this->_ContentRelated = true;
}

GetFavedStickers::GetFavedStickers(int32 hash)
{
	this->_ConstructorID = 235654689;
	this->_ContentRelated = true;
	this->hash = hash;
}
void GetFavedStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
}


void GetFavedStickers::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::FavedStickers*>(Reader.TGReadObject());
}
GetFavedStickers::~GetFavedStickers()
{

}
}//end namespace block
