#include "../Public/InputMessagesFilterPhoneCalls.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterPhoneCalls::InputMessagesFilterPhoneCalls()
{
	this->_ConstructorID = -2134272152;
}

InputMessagesFilterPhoneCalls::InputMessagesFilterPhoneCalls(bool missed)
{
	this->_ConstructorID = -2134272152;
	this->missed = missed;
}
void InputMessagesFilterPhoneCalls::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(missed)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

}


void InputMessagesFilterPhoneCalls::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		missed = true;
	}
	this->_Responded = true;
}
InputMessagesFilterPhoneCalls::~InputMessagesFilterPhoneCalls()
{
}
}//end namespace block
