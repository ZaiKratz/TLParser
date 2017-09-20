#include "../Public/GetMaskStickers.h"


//begin namespace block
namespace MESSAGES
{

GetMaskStickers::GetMaskStickers()
{
	this->_ConstructorID = -1614301083;
	this->_ContentRelated = true;
}

GetMaskStickers::GetMaskStickers(int32 hash)
{
	this->_ConstructorID = -1614301083;
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
}
GetMaskStickers::~GetMaskStickers()
{

}
}//end namespace block
