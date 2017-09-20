#include "../Public/GetArchivedStickers.h"


//begin namespace block
namespace MESSAGES
{

GetArchivedStickers::GetArchivedStickers()
{
	this->_ConstructorID = -1837698729;
	this->_ContentRelated = true;
}

GetArchivedStickers::GetArchivedStickers(bool masks, unsigned long long offset_id, int32 limit)
{
	this->_ConstructorID = -1837698729;
	this->_ContentRelated = true;
	this->masks = masks;
	this->offset_id = offset_id;
	this->limit = limit;
}
void GetArchivedStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!masks)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->offset_id);
	Writer.WriteInt(this->limit);
}


void GetArchivedStickers::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::ArchivedStickers*>(Reader.TGReadObject());
}
GetArchivedStickers::~GetArchivedStickers()
{

}
}//end namespace block