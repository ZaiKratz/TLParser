#include "../Public/GetRecentStickers.h"


//begin namespace block
namespace MESSAGES
{

GetRecentStickers::GetRecentStickers()
{
	this->_ConstructorID = 1587647177;
	this->_ContentRelated = true;
}

GetRecentStickers::GetRecentStickers(bool attached, int32 hash)
{
	this->_ConstructorID = 1587647177;
	this->_ContentRelated = true;
	this->attached = attached;
	this->hash = hash;
}
void GetRecentStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(attached)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->hash);
}


void GetRecentStickers::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::RecentStickers*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetRecentStickers::~GetRecentStickers()
{

}
}//end namespace block
