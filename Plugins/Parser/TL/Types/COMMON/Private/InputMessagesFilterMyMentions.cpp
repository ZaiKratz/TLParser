#include "../Public/InputMessagesFilterMyMentions.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterMyMentions::InputMessagesFilterMyMentions()
{
	this->_ConstructorID = -1696139071;
}
void InputMessagesFilterMyMentions::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterMyMentions::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputMessagesFilterMyMentions::~InputMessagesFilterMyMentions()
{

}
}//end namespace block
