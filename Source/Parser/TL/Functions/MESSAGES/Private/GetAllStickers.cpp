#include "../Public/GetAllStickers.h"


//begin namespace block
namespace MESSAGES
{

GetAllStickers::GetAllStickers()
{
	this->_ConstructorID = 479598769;
	this->_ContentRelated = true;
}

GetAllStickers::GetAllStickers(int32 hash)
{
	this->_ConstructorID = 479598769;
	this->_ContentRelated = true;
	this->hash = hash;
}
void GetAllStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
}


void GetAllStickers::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::AllStickers*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetAllStickers::~GetAllStickers()
{

}
}//end namespace block
