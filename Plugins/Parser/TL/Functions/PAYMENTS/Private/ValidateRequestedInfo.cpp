#include "../Public/ValidateRequestedInfo.h"


//begin namespace block
namespace PAYMENTS
{

ValidateRequestedInfo::ValidateRequestedInfo()
{
	this->_ConstructorID = 1955465847;
	this->_ContentRelated = true;
}

ValidateRequestedInfo::ValidateRequestedInfo(bool save, int32 msg_id, COMMON::PaymentRequestedInfo* info)
{
	this->_ConstructorID = 1955465847;
	this->_ContentRelated = true;
	this->save = save;
	this->msg_id = msg_id;
	this->info = info;
}
void ValidateRequestedInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!save)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->msg_id);
	this->info->OnSend(Writer);
}


void ValidateRequestedInfo::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PAYMENTS::ValidatedRequestedInfo*>(Reader.TGReadObject());
}
ValidateRequestedInfo::~ValidateRequestedInfo()
{

}
}//end namespace block
