#include "../Public/FutureSalt.h"


//begin namespace block
namespace COMMON
{

FutureSalt::FutureSalt()
{
	this->_ConstructorID = -589739767;
}

FutureSalt::FutureSalt(int32 valid_since, int32 valid_until, unsigned long long salt)
{
	this->_ConstructorID = -589739767;
	this->valid_since = valid_since;
	this->valid_until = valid_until;
	this->salt = salt;
}
void FutureSalt::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->valid_since);
	Writer.WriteInt(this->valid_until);
	Writer.WriteLong(this->salt);
}


void FutureSalt::OnResponce(BinaryReader& Reader)
{
	valid_since = Reader.ReadInt();
	valid_until = Reader.ReadInt();
	salt = Reader.ReadLong();
}
FutureSalt::~FutureSalt()
{

}
}//end namespace block
