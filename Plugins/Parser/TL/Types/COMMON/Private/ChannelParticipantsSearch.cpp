#include "../Public/ChannelParticipantsSearch.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsSearch::ChannelParticipantsSearch()
{
	this->_ConstructorID = 64;
}

ChannelParticipantsSearch::ChannelParticipantsSearch(FString q)
{
	this->_ConstructorID = 64;
	this->q = q;
}
void ChannelParticipantsSearch::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->q);
}


void ChannelParticipantsSearch::OnResponce(BinaryReader& Reader)
{
	q = Reader.TGReadString();
}
ChannelParticipantsSearch::~ChannelParticipantsSearch()
{

}
}//end namespace block
