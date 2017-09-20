#include "../Public/InputStickerSetID.h"


//begin namespace block
namespace COMMON
{

InputStickerSetID::InputStickerSetID()
{
	this->_ConstructorID = 1772283805;
}

InputStickerSetID::InputStickerSetID(unsigned long long id, unsigned long long access_hash)
{
	this->_ConstructorID = 1772283805;
	this->id = id;
	this->access_hash = access_hash;
}
void InputStickerSetID::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
}


void InputStickerSetID::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
}
InputStickerSetID::~InputStickerSetID()
{

}
}//end namespace block
