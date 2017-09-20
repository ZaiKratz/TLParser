#include "../Public/FileLocation.h"


//begin namespace block
namespace COMMON
{

FileLocation::FileLocation()
{
	this->_ConstructorID = 1989203539;
}

FileLocation::FileLocation(int32 dc_id, unsigned long long volume_id, int32 local_id, unsigned long long secret)
{
	this->_ConstructorID = 1989203539;
	this->dc_id = dc_id;
	this->volume_id = volume_id;
	this->local_id = local_id;
	this->secret = secret;
}
void FileLocation::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->dc_id);
	Writer.WriteLong(this->volume_id);
	Writer.WriteInt(this->local_id);
	Writer.WriteLong(this->secret);
}


void FileLocation::OnResponce(BinaryReader& Reader)
{
	dc_id = Reader.ReadInt();
	volume_id = Reader.ReadLong();
	local_id = Reader.ReadInt();
	secret = Reader.ReadLong();
}
FileLocation::~FileLocation()
{

}
}//end namespace block
