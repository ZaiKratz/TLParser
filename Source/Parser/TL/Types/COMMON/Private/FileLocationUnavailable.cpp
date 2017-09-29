#include "../Public/FileLocationUnavailable.h"


//begin namespace block
namespace COMMON
{

FileLocationUnavailable::FileLocationUnavailable()
{
	this->_ConstructorID = 2086234950;
}

FileLocationUnavailable::FileLocationUnavailable(unsigned long long volume_id, int32 local_id, unsigned long long secret)
{
	this->_ConstructorID = 2086234950;
	this->volume_id = volume_id;
	this->local_id = local_id;
	this->secret = secret;
}
void FileLocationUnavailable::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->volume_id);
	Writer.WriteInt(this->local_id);
	Writer.WriteLong(this->secret);
}


void FileLocationUnavailable::OnResponce(BinaryReader& Reader)
{
	volume_id = Reader.ReadLong();
	local_id = Reader.ReadInt();
	secret = Reader.ReadLong();
	this->_Responded = true;
}
FileLocationUnavailable::~FileLocationUnavailable()
{

}
}//end namespace block
