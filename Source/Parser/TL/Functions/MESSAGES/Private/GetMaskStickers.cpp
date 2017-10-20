#include "../Public/GetMaskStickers.h"


//begin namespace block
namespace MESSAGES
{

GetMaskStickers::GetMaskStickers()
{
	this->_ConstructorID = 1706608543;
	this->_ContentRelated = true;
}

GetMaskStickers::GetMaskStickers(int32 hash)
{
	this->_ConstructorID = 1706608543;
	this->_ContentRelated = true;
	this->hash = hash;
}
void GetMaskStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
}


void GetMaskStickers::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::AllStickers*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetMaskStickers::~GetMaskStickers()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
