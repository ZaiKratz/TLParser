#include "../Public/MessageActionPhoneCall.h"


//begin namespace block
namespace COMMON
{

MessageActionPhoneCall::MessageActionPhoneCall()
{
	this->_ConstructorID = -2132731265;
}

MessageActionPhoneCall::MessageActionPhoneCall(unsigned long long call_id, PRIVATE::PhoneCallDiscardReason*  reason, int32 duration)
{
	this->_ConstructorID = -2132731265;
	this->call_id = call_id;
	this->reason = reason;
	this->duration = duration;
}
void MessageActionPhoneCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(reason)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(duration)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->call_id);
	if(!this->reason)
	{
	this->reason->OnSend(Writer);
	}
	if(!this->duration)
	{
	Writer.WriteInt(this->duration);
	}
}


void MessageActionPhoneCall::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	call_id = Reader.ReadLong();
	if((Flags & (1 << 0)) != 0) 
	{
	reason = reinterpret_cast<PRIVATE::PhoneCallDiscardReason* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 1)) != 0) 
	{
	duration = Reader.ReadInt();
	}
	this->_Responded = true;
}
MessageActionPhoneCall::~MessageActionPhoneCall()
{

}
}//end namespace block
