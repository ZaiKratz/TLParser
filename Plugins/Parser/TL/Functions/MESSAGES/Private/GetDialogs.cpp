#include "../Public/GetDialogs.h"


//begin namespace block
namespace MESSAGES
{

GetDialogs::GetDialogs()
{
	this->_ConstructorID = -978773223;
	this->_ContentRelated = true;
}

GetDialogs::GetDialogs(bool exclude_pinned, FDateTime offset_date, int32 offset_id, PRIVATE::InputPeer* offset_peer, int32 limit)
{
	this->_ConstructorID = -978773223;
	this->_ContentRelated = true;
	this->exclude_pinned = exclude_pinned;
	this->offset_date = offset_date;
	this->offset_id = offset_id;
	this->offset_peer = offset_peer;
	this->limit = limit;
}
void GetDialogs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!exclude_pinned)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteDate(this->offset_date);
	Writer.WriteInt(this->offset_id);
	this->offset_peer->OnSend(Writer);
	Writer.WriteInt(this->limit);
}


void GetDialogs::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Dialogs*>(Reader.TGReadObject());
}
GetDialogs::~GetDialogs()
{

}
}//end namespace block
