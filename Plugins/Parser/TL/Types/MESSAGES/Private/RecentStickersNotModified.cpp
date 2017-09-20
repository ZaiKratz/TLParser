#include "../Public/RecentStickersNotModified.h"


//begin namespace block
namespace MESSAGES
{

RecentStickersNotModified::RecentStickersNotModified()
{
	this->_ConstructorID = 64;
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
}
RecentStickersNotModified::~RecentStickersNotModified()
{

}
}//end namespace block
