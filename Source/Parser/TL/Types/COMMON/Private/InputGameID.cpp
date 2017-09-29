#include "../Public/InputGameID.h"


//begin namespace block
namespace COMMON
{

InputGameID::InputGameID()
{
	this->_ConstructorID = 53231223;
}

InputGameID::InputGameID(unsigned long long id, unsigned long long access_hash)
{
	this->_ConstructorID = 53231223;
	this->id = id;
	this->access_hash = access_hash;
}
void InputGameID::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
}


void InputGameID::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	this->_Responded = true;
}
InputGameID::~InputGameID()
{

}
}//end namespace block
