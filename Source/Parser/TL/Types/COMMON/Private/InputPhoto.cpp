#include "../Public/InputPhoto.h"


//begin namespace block
namespace COMMON
{

InputPhoto::InputPhoto()
{
	this->_ConstructorID = -74070332;
}

InputPhoto::InputPhoto(unsigned long long id, unsigned long long access_hash)
{
	this->_ConstructorID = -74070332;
	this->id = id;
	this->access_hash = access_hash;
}
void InputPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
}


void InputPhoto::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	this->_Responded = true;
}
InputPhoto::~InputPhoto()
{
}
}//end namespace block
