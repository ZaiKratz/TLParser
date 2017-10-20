#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/WebPage.h"

//begin namespace block
namespace COMMON
{
class UpdateWebPage : public TLBaseObject
{
public:
	UpdateWebPage();
	UpdateWebPage(COMMON::WebPage* webpage, int32 pts, int32 pts_count);

	~UpdateWebPage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::WebPage*  Getwebpage() const
	{
		 return this->webpage;
	}

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 GetPtsCount() const
	{
		 return this->pts_count;
	}

private:
	COMMON::WebPage* webpage;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
