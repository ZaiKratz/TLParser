#include "../Public/ResolveUsername.h"


//begin namespace block
namespace CONTACTS
{

ResolveUsername::ResolveUsername()
{
	this->_ConstructorID = -1546961671;
	this->_ContentRelated = true;
}

ResolveUsername::ResolveUsername(FString username)
{
	this->_ConstructorID = -1546961671;
	this->_ContentRelated = true;
	this->username = username;
}
void ResolveUsername::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->username);
}


void ResolveUsername::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CONTACTS::ResolvedPeer*>(Reader.TGReadObject());
}
ResolveUsername::~ResolveUsername()
{

}
}//end namespace block
