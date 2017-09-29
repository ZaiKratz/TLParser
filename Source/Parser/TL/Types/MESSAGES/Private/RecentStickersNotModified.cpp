#include "../Public/RecentStickersNotModified.h"


//begin namespace block
namespace MESSAGES
{

RecentStickersNotModified::RecentStickersNotModified()
{
	this->_ConstructorID = 186120336;
}
void RecentStickersNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void RecentStickersNotModified::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
RecentStickersNotModified::~RecentStickersNotModified()
{

}
}//end namespace block
