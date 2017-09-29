#include "../Public/DcOption.h"


//begin namespace block
namespace COMMON
{

DcOption::DcOption()
{
	this->_ConstructorID = 98092748;
}

DcOption::DcOption(bool ipv6, bool media_only, bool tcpo_only, bool cdn, bool Static, int32 id, FString ip_address, int32 port)
{
	this->_ConstructorID = 98092748;
	this->ipv6 = ipv6;
	this->media_only = media_only;
	this->tcpo_only = tcpo_only;
	this->cdn = cdn;
	this->Static = Static;
	this->id = id;
	this->ip_address = ip_address;
	this->port = port;
}
void DcOption::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(ipv6)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(media_only)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(tcpo_only)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(cdn)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(Static)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->id);
	Writer.TGWriteString(this->ip_address);
	Writer.WriteInt(this->port);
}


void DcOption::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		ipv6 = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		media_only = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		tcpo_only = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		cdn = true;
	}
	if((Flags & (1 << 4)) != 0) 
	{
		Static = true;
	}
	id = Reader.ReadInt();
	ip_address = Reader.TGReadString();
	port = Reader.ReadInt();
	this->_Responded = true;
}
DcOption::~DcOption()
{

}
}//end namespace block
