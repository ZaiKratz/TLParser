#include "../Public/InputAppEvent.h"


//begin namespace block
namespace COMMON
{

InputAppEvent::InputAppEvent()
{
	this->_ConstructorID = -1470757257;
}

InputAppEvent::InputAppEvent(double time, FString type, unsigned long long peer, FString data)
{
	this->_ConstructorID = -1470757257;
	this->time = time;
	this->type = type;
	this->peer = peer;
	this->data = data;
}
void InputAppEvent::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteDouble(this->time);
	Writer.TGWriteString(this->type);
	Writer.WriteLong(this->peer);
	Writer.TGWriteString(this->data);
}


void InputAppEvent::OnResponce(BinaryReader& Reader)
{
	time = Reader.ReadDouble();
	type = Reader.TGReadString();
	peer = Reader.ReadLong();
	data = Reader.TGReadString();
}
InputAppEvent::~InputAppEvent()
{

}
}//end namespace block
