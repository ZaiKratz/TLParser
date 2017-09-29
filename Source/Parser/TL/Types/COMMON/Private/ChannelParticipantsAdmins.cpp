#include "../Public/ChannelParticipantsAdmins.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsAdmins::ChannelParticipantsAdmins()
{
	this->_ConstructorID = -1268741783;
}
void ChannelParticipantsAdmins::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ChannelParticipantsAdmins::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
ChannelParticipantsAdmins::~ChannelParticipantsAdmins()
{

}
}//end namespace block
