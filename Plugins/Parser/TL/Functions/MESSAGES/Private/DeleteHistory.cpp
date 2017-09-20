#include "../Public/DeleteHistory.h"


//begin namespace block
namespace MESSAGES
{

DeleteHistory::DeleteHistory()
{
	this->_ConstructorID = 156959004;
	this->_ContentRelated = true;
}

DeleteHistory::DeleteHistory(bool just_clear, PRIVATE::InputPeer* peer, int32 max_id)
{
	this->_ConstructorID = 156959004;
	this->_ContentRelated = true;
	this->just_clear = just_clear;
	this->peer = peer;
	this->max_id = max_id;
}
void DeleteHistory::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!just_clear)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->peer->OnSend(Writer);
	Writer.WriteInt(this->max_id);
}


void DeleteHistory::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::AffectedHistory*>(Reader.TGReadObject());
}
DeleteHistory::~DeleteHistory()
{

}
}//end namespace block
