#!/usr/bin/python3
#coding:UTF-8

import requests

Date = []
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) ' 'Chrome/51.0.2704.63 Safari/537.36'}

for i in range(0, 100):
	url = r'https://www.zhihu.com/api/v4/questions/39474276/answers?include=data[*].is_normal,admin_closed_comment,reward_info,is_collapsed,annotation_action,annotation_detail,collapse_reason,is_sticky,collapsed_by,suggest_edit,comment_count,can_comment,content,editable_content,attachment,voteup_count,reshipment_settings,comment_permission,created_time,updated_time,review_info,relevant_info,question,excerpt,is_labeled,paid_info,paid_info_content,relationship.is_authorized,is_author,voting,is_thanked,is_nothelp,is_recognized;data[*].mark_infos[*].url;data[*].author.follower_count,vip_info,badge[*].topics;data[*].settings.table_of_content.enabled&limit=1&offset=' + str(i) + r'&platform=desktop&sort_by=default'

	r = requests.get(url, headers = headers)
	r.raise_for_status()
	r.encoding = 'utf-8'

	Date.append(r.text);

Date = list(set(Date))

for data in Date:
	with open('data', 'a+') as f:
		f.write(data + '\n--------\n')
