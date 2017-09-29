#include "../Public/PhoneCallWaiting.h"


//begin namespace block
namespace COMMON
{

PhoneCallWaiting::PhoneCallWaiting()
{
	this->_ConstructorID = 462375633;
}

PhoneCallWaiting::PhoneCallWaiting(unsigned long long id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, COMMON::PhoneCallProtocol*  protocol, FDateTime receive_date)
{
	this->_ConstructorID = 462375633;
	this->id = id;
	this->access_hash = access_hash;
	this->date = date;
	this->admin_id = admin_id;
	this->participant_id = participant_id;
	this->protocol = protocol;
	this->receive_date = receive_date;
}
void PhoneCallWaiting::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(receive_date == FDateTime::MinValue())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->admin_id);
	Writer.WriteInt(this->participant_id);
	this->protocol->OnSend(Writer);
	if(receive_date == FDateTime::MinValue())
	{
	Writer.TGWriteDate(this->receive_date);
	}
}


void PhoneCallWaiting::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	date = Reader.TGReadDate();
	admin_id = Reader.ReadInt();
	participant_id = Reader.ReadInt();
	protocol = reinterpret_cast<COMMON::PhoneCallProtocol* >(Reader.TGReadObject());
	if((Flags & (1 << 0)) != 0) 
	{
	receive_date = Reader.TGReadDate();
	}
	this->_Responded = true;
}
PhoneCallWaiting::~PhoneCallWaiting()
{

}
}//end namespace block
