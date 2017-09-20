#include "../Public/ChannelParticipantsAdmins.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsAdmins::ChannelParticipantsAdmins()
{
	this->_ConstructorID = 1770610868;
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
}
ChannelParticipantsAdmins::~ChannelParticipantsAdmins()
{

}
}//end namespace block
