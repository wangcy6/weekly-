 ##   Two-phase Commit
 
## 1 when
## 2 what
## 3 optimization
## 4 future

----------------------------------------
# when
二阶段提交算法的成立基于以下假设：

- 该分布式系统中，存在一个节点作为协调者(Coordinator)，其他节点作为参与者(Participants)。且节点之间可以进行网络通信。
- 所有节点都采用预写式日志，且日志被写入后即被保持在可靠的存储设备上，即使节点损坏不会导致日志数据的消失。
- 所有节点不会永久性损坏，即使损坏后仍然可以恢复。
--------------------------------------------
## what
协调者                                              参与者
                              QUERY TO COMMIT
                -------------------------------->
                              VOTE YES/NO           prepare*/abort*
                <-------------------------------
commit*/abort*                COMMIT/ROLLBACK
                -------------------------------->
                              ACKNOWLEDGMENT        commit*/abort*
                <--------------------------------  
end
"*" 所标记的操作意味着此类操作必须记录在稳固存储上

-------------------------------------------
# optimization -failover 


## 1 failed model 

## 2 state machine





https://www.hexiangyu.me/2019/03/31/2pc/

----------------------------------------