#include "../Public/GetFavedStickers.h"


//begin namespace block
namespace MESSAGES
{

GetFavedStickers::GetFavedStickers()
{
	this->_ConstructorID = 567151374;
	this->_ContentRelated = true;
}

GetFavedStickers::GetFavedStickers(int32 hash)
{
	this->_ConstructorID = 567151374;
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
	this->_Responded = true;
}
GetFavedStickers::~GetFavedStickers()
{

}
}//end namespace block
