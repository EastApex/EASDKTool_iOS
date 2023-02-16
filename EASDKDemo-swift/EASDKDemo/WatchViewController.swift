//
//  WatchViewController.swift
//  EASDKDemo
//
//  Created by Aye on 2023/2/16.
//

import UIKit

class WatchViewController: UIViewController , UITableViewDelegate, UITableViewDataSource {
    
    var tableView : UITableView!
    static let cellId = "cellIdl"
    var dataSource : NSMutableArray!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.title = "Watch【手表】";
        
        view.backgroundColor = UIColor.white
        
        tableView = UITableView.init(frame: view.bounds, style: .grouped)
        tableView.contentInsetAdjustmentBehavior = .never
        tableView.delegate = self
        tableView.dataSource = self
        view.addSubview(tableView)
        
        tableView.snp.makeConstraints { make in
            
            make.top.equalTo(view.safeAreaLayoutGuide.snp.top)
            make.left.equalTo(view)
            make.right.equalTo(view)
            make.bottom.equalTo(view.safeAreaLayoutGuide.snp.bottom)
        }
        
        dataSource = NSMutableArray.init();
        
        let setList:NSArray = [
            "Get Value",
            "Set Value",
            "Get big data",
            "OTA & Watch Face",
            "Control Watch",
            "Unstrap a Watch",
        ]
        let setInfo = NSMutableDictionary.init()
        setInfo.setObject(setList, forKey: "list" as NSCopying)
        dataSource.add(setInfo)

        
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        var cell = tableView.dequeueReusableCell(withIdentifier: ListViewController.cellId)
        if cell == nil {
            cell = UITableViewCell.init(style: .default, reuseIdentifier: ListViewController.cellId)
        }
        let info = dataSource.object(at: indexPath.section) as! NSMutableDictionary
        let list = info.object(forKey: "list") as! NSArray
        cell?.textLabel?.text = list.object(at: indexPath.row) as? String
        cell?.textLabel?.numberOfLines = 0
        return cell!
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        let info = dataSource.object(at: section) as! NSMutableDictionary
        let list = info.object(forKey: "list") as! NSArray
        return list.count
    }
    func numberOfSections(in tableView: UITableView) -> Int {
        return dataSource.count
    }
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        
        let headerView = UIView.init(frame: CGRect.init(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: 0))
        return headerView
    }
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        let info = dataSource.object(at: indexPath.section) as! NSMutableDictionary
        let list = info.object(forKey: "list") as! NSArray
        let title:String = (list.object(at: indexPath.row) as? String)!
        
        switch indexPath.row {
        case 0:  do {
            let rCtl = ListViewController()
            rCtl.type = 0;
            rCtl.title = title
            self.navigationController?.pushViewController(rCtl, animated: true)
        };break
        case 1:   do {
            let rCtl = ListViewController()
            rCtl.type = 1;
            rCtl.title = title
            self.navigationController?.pushViewController(rCtl, animated: true)
        };break
        case 2:   do {
            let rCtl = GetBigDataViewController()
            rCtl.title = title
            self.navigationController?.pushViewController(rCtl, animated: true)
        };break
        case 3:   do {
            let rCtl = OTAViewController()
            rCtl.title = title
            self.navigationController?.pushViewController(rCtl, animated: true)
        };break
        case 4:   do {
            let rCtl = ControlWatchViewController()
            rCtl.title = title
            self.navigationController?.pushViewController(rCtl, animated: true)
        };break
        case 5:   do {
            let rCtl = UnbindViewController()
            rCtl.title = title
            self.navigationController?.pushViewController(rCtl, animated: true)
        };break
        default:break;
        }
    }
}
