#include "../Public/InputFileLocation.h"


//begin namespace block
namespace COMMON
{

InputFileLocation::InputFileLocation()
{
	this->_ConstructorID = -1770953964;
}

InputFileLocation::InputFileLocation(unsigned long long volume_id, int32 local_id, unsigned long long secret)
{
	this->_ConstructorID = -1770953964;
	this->volume_id = volume_id;
	this->local_id = local_id;
	this->secret = secret;
}
void InputFileLocation::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->volume_id);
	Writer.WriteInt(this->local_id);
	Writer.WriteLong(this->secret);
}


void InputFileLocation::OnResponce(BinaryReader& Reader)
{
	volume_id = Reader.ReadLong();
	local_id = Reader.ReadInt();
	secret = Reader.ReadLong();
}
InputFileLocation::~InputFileLocation()
{

}
}//end namespace block
