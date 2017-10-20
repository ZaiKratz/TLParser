#include "../Public/PhoneCallDiscarded.h"


//begin namespace block
namespace COMMON
{

PhoneCallDiscarded::PhoneCallDiscarded()
{
	this->_ConstructorID = 1355435489;
}

PhoneCallDiscarded::PhoneCallDiscarded(bool need_rating, bool need_debug, unsigned long long id, TLBaseObject*  reason, int32 duration)
{
	this->_ConstructorID = 1355435489;
	this->need_rating = need_rating;
	this->need_debug = need_debug;
	this->id = id;
	this->reason = reason;
	this->duration = duration;
}
void PhoneCallDiscarded::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(need_rating)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(need_debug)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
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

	Writer.WriteLong(this->id);
	if(this->reason)
	{
	this->reason->OnSend(Writer);
	}
	if(this->duration)
	{
	Writer.WriteInt(this->duration);
	}
}


void PhoneCallDiscarded::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 2)) != 0) 
	{
		need_rating = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		need_debug = true;
	}
	id = Reader.ReadLong();
	if((Flags & (1 << 0)) != 0) 
	{
	reason = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 1)) != 0) 
	{
	duration = Reader.ReadInt();
	}
	this->_Responded = true;
}
PhoneCallDiscarded::~PhoneCallDiscarded()
{
	if(this->reason)
	{
		delete this->reason;
	}
}
}//end namespace block
