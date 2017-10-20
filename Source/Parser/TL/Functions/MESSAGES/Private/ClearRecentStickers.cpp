#include "../Public/ClearRecentStickers.h"


//begin namespace block
namespace MESSAGES
{

ClearRecentStickers::ClearRecentStickers()
{
	this->_ConstructorID = -1986437075;
	this->_ContentRelated = true;
}

ClearRecentStickers::ClearRecentStickers(bool attached)
{
	this->_ConstructorID = -1986437075;
	this->_ContentRelated = true;
	this->attached = attached;
}
void ClearRecentStickers::OnSend(BinaryWriter& Writer)
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

}


void ClearRecentStickers::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ClearRecentStickers::~ClearRecentStickers()
{
}
}//end namespace block
