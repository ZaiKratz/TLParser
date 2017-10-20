#include "../Public/ChannelAdminLogEvent.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEvent::ChannelAdminLogEvent()
{
	this->_ConstructorID = 995769920;
}

ChannelAdminLogEvent::ChannelAdminLogEvent(unsigned long long id, FDateTime date, int32 user_id, TLBaseObject*  action)
{
	this->_ConstructorID = 995769920;
	this->id = id;
	this->date = date;
	this->user_id = user_id;
	this->action = action;
}
void ChannelAdminLogEvent::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->user_id);
	this->action->OnSend(Writer);
}


void ChannelAdminLogEvent::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	date = Reader.TGReadDate();
	user_id = Reader.ReadInt();
	action = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChannelAdminLogEvent::~ChannelAdminLogEvent()
{
	if(this->action)
	{
		delete this->action;
	}
}
}//end namespace block
