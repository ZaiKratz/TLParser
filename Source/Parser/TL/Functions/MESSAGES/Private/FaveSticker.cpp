#include "../Public/FaveSticker.h"


//begin namespace block
namespace MESSAGES
{

FaveSticker::FaveSticker()
{
	this->_ConstructorID = -1174420133;
	this->_ContentRelated = true;
}

FaveSticker::FaveSticker(COMMON::InputDocument*  id, bool unfave)
{
	this->_ConstructorID = -1174420133;
	this->_ContentRelated = true;
	this->id = id;
	this->unfave = unfave;
}
void FaveSticker::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
	Writer.WriteBool(this->unfave);
}


void FaveSticker::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
FaveSticker::~FaveSticker()
{

}
}//end namespace block
