#include "../Public/DeleteAccount.h"


//begin namespace block
namespace ACCOUNT
{

DeleteAccount::DeleteAccount()
{
	this->_ConstructorID = 189697345;
	this->_ContentRelated = true;
}

DeleteAccount::DeleteAccount(FString reason)
{
	this->_ConstructorID = 189697345;
	this->_ContentRelated = true;
	this->reason = reason;
}
void DeleteAccount::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->reason);
}


void DeleteAccount::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
DeleteAccount::~DeleteAccount()
{

}
}//end namespace block
